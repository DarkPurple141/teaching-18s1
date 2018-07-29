<template lang="html">
   <div class="card">
      <h4>Week {{ number + 1 }}</h4>
      <p>{{ meta.description }}</p>
      <router-link :to="{ name: 'Lab', params: { week: this.link} }">More</router-link>
   </div>
</template>

<script>
export default {
   props: {
      link: String,
      meta: Object,
      number: Number
   }
}
</script>

<style lang="less" scoped>
@import '../assets/colors.less';
.card {
   margin: 20px 0px 20px 20px;
   width: 150px;
   flex: 1 0 200px;
   display: flex;
   height: 200px;
   flex-direction: column;
   align-items: center;
   justify-content: space-between;
   border: 1px solid rgba(200, 200, 200, 0.5);
   border-radius: 0.25em;
   box-shadow: 2px 2px 5px 0px lighten(rgba(200, 200, 200, 0.5), 0.4);

   * {
      width: 80%;
      padding: 10px;
   }

   h4 {
      font-size: 1.25rem;
      color: #efefef;
      width: 100%;
      background-color: @accent;
      padding: 20px 0px;
   }
}

</style>
